#include "dust.h"
#include "block.h"
#include "item.h"
#include "log.h"

const char* init() {
	char* mod_id = "cmod";

	log_info("Hello from C!");

	// Create block
	Block block = create_block(create_block_settings());
	register_block(create_identifier(mod_id, "c_block"), block);

	// Create Block Item
	Item block_item = create_block_item(block, create_item_settings());
	register_item(create_identifier(mod_id, "c_block"), block_item);

	// Create Item
	ItemSettings settings = create_item_settings();
	settings = item_settings_max_count(settings, 42);
	Item item = create_item(settings);
	register_item(create_identifier(mod_id, "c_item"), item);

	return mod_id;
}