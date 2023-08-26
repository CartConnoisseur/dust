package re.larimo.calvin.dust;

import net.fabricmc.api.ModInitializer;
import net.fabricmc.loader.api.FabricLoader;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.nio.file.Path;

public class Dust implements ModInitializer {
    public static final String MOD_ID = "dust";

    public static final Logger LOGGER = LogManager.getLogger("Dust/Java");

    @Override
    public void onInitialize() {
        Path modDir = FabricLoader.getInstance().getGameDir().resolve("dust");
        modDir.toFile().mkdir();

        Path internalDir = modDir.resolve("internal");
        internalDir.toFile().mkdir();

        LOGGER.info("Loading Dust wrapper (internal/wrapper.so)");
        Path wrapper = internalDir.resolve("wrapper.so");
        if (!wrapper.toFile().exists()) throw new RuntimeException("Dust wrapper not found!");
        System.load(wrapper.toString());

        LOGGER.info("Initializing Dust wrapper");
        load(
                LogManager.getLogger("Dust/Wrapper"),
                LogManager.getLogger("Dust"),
                modDir.toString(),
                MOD_ID
        );
    }

    private native void load(Logger wrapperLogger, Logger coreLogger, String modDir, String modId);
}
