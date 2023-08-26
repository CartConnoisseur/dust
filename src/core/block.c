#include <jni.h>
#include "env.h"
#include "log.h"
#include "dust.h"
#include "block.h"


Block create_block(BlockSettings settings) {
	jclass block_class = (*env)->FindClass(env, "net/minecraft/block/Block");
	jmethodID block_constructor = (*env)->GetMethodID(env, block_class, "<init>", "(Lnet/minecraft/block/AbstractBlock$Settings;)V");

	return (*env)->NewObject(env, block_class, block_constructor, settings);
}

Block register_block(Identifier identifier, Block block) {
	jclass registry_class = (*env)->FindClass(env, "net/minecraft/registry/Registry");
	jmethodID register_method = (*env)->GetStaticMethodID(env, registry_class, "register", "(Lnet/minecraft/registry/Registry;Lnet/minecraft/util/Identifier;Ljava/lang/Object;)Ljava/lang/Object;");

	jclass registries_class = (*env)->FindClass(env, "net/minecraft/registry/Registries");
	jfieldID block_registry_field = (*env)->GetStaticFieldID(env, registries_class, "BLOCK", "Lnet/minecraft/registry/DefaultedRegistry;");
	jobject block_registry = (*env)->GetStaticObjectField(env, registries_class, block_registry_field);

	return (*env)->CallStaticObjectMethod(env, registry_class, register_method, block_registry, identifier, block);
}


jclass fabric_block_settings_class;

BlockSettings create_block_settings() {
	fabric_block_settings_class = (*env)->FindClass(env, "net/fabricmc/fabric/api/object/builder/v1/block/FabricBlockSettings");
	jmethodID create = (*env)->GetStaticMethodID(env, fabric_block_settings_class, "create", "()Lnet/fabricmc/fabric/api/object/builder/v1/block/FabricBlockSettings;");

	return (*env)->CallStaticObjectMethod(env, fabric_block_settings_class, create);
}

BlockSettings block_settings_no_collision(BlockSettings settings) {
	jmethodID set_no_collision = (*env)->GetMethodID(env, fabric_block_settings_class, "noCollision", "()Lnet/fabricmc/fabric/api/object/builder/v1/block/FabricBlockSettings;");
	return (*env)->CallObjectMethod(env, settings, set_no_collision);
}
BlockSettings block_settings_non_opaque(BlockSettings settings) {
	jmethodID set_non_opaque = (*env)->GetMethodID(env, fabric_block_settings_class, "nonOpaque", "()Lnet/fabricmc/fabric/api/object/builder/v1/block/FabricBlockSettings;");
	return (*env)->CallObjectMethod(env, settings, set_non_opaque);
}
BlockSettings block_settings_slipperiness(BlockSettings settings, float slipperiness) {
	jmethodID set_slipperiness = (*env)->GetMethodID(env, fabric_block_settings_class, "slipperiness", "(F)Lnet/fabricmc/fabric/api/object/builder/v1/block/FabricBlockSettings;");
	return (*env)->CallObjectMethod(env, settings, set_slipperiness, slipperiness);
}
BlockSettings block_settings_velocity_multiplier(BlockSettings settings, float velocity_multiplier) {
	jmethodID set_velocity_multiplier = (*env)->GetMethodID(env, fabric_block_settings_class, "velocityMultiplier", "(F)Lnet/fabricmc/fabric/api/object/builder/v1/block/FabricBlockSettings;");
	return (*env)->CallObjectMethod(env, settings, set_velocity_multiplier, velocity_multiplier);
}
BlockSettings block_settings_jump_velocity_multiplier(BlockSettings settings, float jump_velocity_multiplier) {
	jmethodID set_jump_velocity_multiplier = (*env)->GetMethodID(env, fabric_block_settings_class, "jumpVelocityMultiplier", "(F)Lnet/fabricmc/fabric/api/object/builder/v1/block/FabricBlockSettings;");
	return (*env)->CallObjectMethod(env, settings, set_jump_velocity_multiplier, jump_velocity_multiplier);
}
// sounds goes here
// luminance goes here
BlockSettings block_settings_strength_hardness_resistance(BlockSettings settings, float hardness, float resistance) {
	jmethodID set_strength = (*env)->GetMethodID(env, fabric_block_settings_class, "strength", "(FF)Lnet/fabricmc/fabric/api/object/builder/v1/block/FabricBlockSettings;");
	return (*env)->CallObjectMethod(env, settings, set_strength, hardness, resistance);
}
BlockSettings block_settings_break_instantly(BlockSettings settings) {
	jmethodID set_break_instantly = (*env)->GetMethodID(env, fabric_block_settings_class, "breakInstantly", "()Lnet/fabricmc/fabric/api/object/builder/v1/block/FabricBlockSettings;");
	return (*env)->CallObjectMethod(env, settings, set_break_instantly);
}
BlockSettings block_settings_strength(BlockSettings settings, float strength) {
	jmethodID set_strength = (*env)->GetMethodID(env, fabric_block_settings_class, "strength", "(F)Lnet/fabricmc/fabric/api/object/builder/v1/block/FabricBlockSettings;");
	return (*env)->CallObjectMethod(env, settings, set_strength, strength);
}
