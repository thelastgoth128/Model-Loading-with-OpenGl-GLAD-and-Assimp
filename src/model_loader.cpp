#include "model_loader.hpp"
#include "model.h" // Your actual model class

static Model* ourModel = nullptr;

void load_model_from_path(const char* path) {
    std::cout << "[ModelLoader] Loading model from: " << path << std::endl;

    std::cout << "Running the Try method " << path << std::endl;

    try {
        if (ourModel) {
            delete ourModel;
            std::cout << "[ModelLoader] Previous model deleted.\n";
        }
        
        std::string fixedPath = std::string(path);
        std::replace(fixedPath.begin(), fixedPath.end(), '\\', '/');
        std::cout << "[ModelLoader] Final normalized path: " << fixedPath << std::endl;

        ourModel = new Model(fixedPath.c_str());
        
        std::cout << "[ModelLoader] Model loaded successfully.\n";
        
    } catch (const std::exception& e) {
        std::cerr << "[ModelLoader] Exception: " << e.what() << std::endl;
    }
}


Model* get_loaded_model() {
    return ourModel;
}