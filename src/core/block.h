#pragma once
#include "dust.h"

typedef void* Block;
typedef void* BlockSettings;


extern Block create_block(BlockSettings settings);
extern Block register_block(Identifier identifier, Block block);


extern BlockSettings create_block_settings();

extern BlockSettings block_settings_no_collision(BlockSettings settings);
extern BlockSettings block_settings_non_opaque(BlockSettings settings);
extern BlockSettings block_settings_slipperiness(BlockSettings settings, float slipperiness);
extern BlockSettings block_settings_velocity_multiplier(BlockSettings settings, float velocity_multiplier);
extern BlockSettings block_settings_jump_velocity_multiplier(BlockSettings settings, float jump_velocity_multiplier);
// sounds goes here
// luminance goes here
extern BlockSettings block_settings_strength_hardness_resistance(BlockSettings settings, float hardness, float resistance);
extern BlockSettings block_settings_break_instantly(BlockSettings settings);
extern BlockSettings block_settings_strength(BlockSettings settings, float strength);