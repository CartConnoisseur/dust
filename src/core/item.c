#include <jni.h>
#include "env.h"
#include "dust.h"
#include "item.h"
#include "block.h"


Item create_item(ItemSettings settings) {
	jclass item_class = (*env)->FindClass(env, "net/minecraft/item/Item");
	jmethodID constructor = (*env)->GetMethodID(env, item_class, "<init>", "(Lnet/minecraft/item/Item$Settings;)V");

	return (*env)->NewObject(env, item_class, constructor, settings);
}

Item create_block_item(Block block, ItemSettings settings) {
	jclass block_item_class = (*env)->FindClass(env, "net/minecraft/item/BlockItem");
	jmethodID constructor = (*env)->GetMethodID(env, block_item_class, "<init>", "(Lnet/minecraft/block/Block;Lnet/minecraft/item/Item$Settings;)V");

	return (*env)->NewObject(env, block_item_class, constructor, block, settings);
}

Item register_item(Identifier identifier, Item item) {
	jclass registry_class = (*env)->FindClass(env, "net/minecraft/registry/Registry");
	jmethodID register_method = (*env)->GetStaticMethodID(env, registry_class, "register", "(Lnet/minecraft/registry/Registry;Lnet/minecraft/util/Identifier;Ljava/lang/Object;)Ljava/lang/Object;");

	jclass registries_class = (*env)->FindClass(env, "net/minecraft/registry/Registries");
	jfieldID item_registry_field = (*env)->GetStaticFieldID(env, registries_class, "ITEM", "Lnet/minecraft/registry/DefaultedRegistry;");
	jobject item_registry = (*env)->GetStaticObjectField(env, registries_class, item_registry_field);

	return (*env)->CallStaticObjectMethod(env, registry_class, register_method, item_registry, identifier, item);
}


jclass fabric_item_settings_class;

ItemSettings create_item_settings() {
	fabric_item_settings_class = (*env)->FindClass(env, "net/fabricmc/fabric/api/item/v1/FabricItemSettings");
	jmethodID constructor = (*env)->GetMethodID(env, fabric_item_settings_class, "<init>", "()V");

	return (*env)->NewObject(env, fabric_item_settings_class, constructor);
}

// equipmentslot, maybe
// customdamage, maybe
// food
ItemSettings item_settings_max_count(ItemSettings settings, int max_count) {
	jmethodID set_max_count = (*env)->GetMethodID(env, fabric_item_settings_class, "maxCount", "(I)Lnet/fabricmc/fabric/api/item/v1/FabricItemSettings;");
	return (*env)->CallObjectMethod(env, settings, set_max_count, max_count);
}