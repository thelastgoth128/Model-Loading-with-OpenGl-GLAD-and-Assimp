#pragma once
#include "model.h"

#ifdef __cplusplus
extern "C" {
#endif

void load_model_from_path(const char* path);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
Model* get_loaded_model();
#endif

extern Model* ourModel;

