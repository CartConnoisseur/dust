package re.larimo.calvin.dust.client;

import net.fabricmc.api.ClientModInitializer;
import re.larimo.calvin.dust.Dust;

@net.fabricmc.api.Environment(net.fabricmc.api.EnvType.CLIENT)
public class DustClient implements ClientModInitializer {

    @Override
    public void onInitializeClient() {
        Dust.LOGGER.info("(Not) Initializing Dust client");
        load_client();
    }

    private native void load_client();
}
