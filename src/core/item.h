#pragma once
#include "dust.h"
#include "block.h"

typedef void* Item;
typedef void* ItemSettings;


extern Item create_item(ItemSettings settings);
extern Item create_block_item(Block block, ItemSettings settings);
extern Item register_item(Identifier identifier, Item item);


extern ItemSettings create_item_settings();

extern ItemSettings item_settings_max_count(ItemSettings settings, int max_count);