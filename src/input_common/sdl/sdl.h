// Copyright 2017 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

#include <memory>
#include <vector>
#include "common/param_package.h"
#include "core/frontend/input.h"
#include "input_common/main.h"

union SDL_Event;

namespace InputCommon {
namespace SDL {

/// Initializes and registers SDL device factories
void Init();

/// Unresisters SDL device factories and shut them down.
void Shutdown();

/// Creates a ParamPackage from an SDL_Event that can directly be used to create a ButtonDevice
Common::ParamPackage SDLEventToButtonParamPackage(const SDL_Event& event);

namespace Polling {

/// Get all DevicePoller that use the SDL backend for a specific device type
std::vector<std::unique_ptr<InputCommon::Polling::DevicePoller>> GetPollers(
    InputCommon::Polling::DeviceType type);

} // namespace Polling
} // namespace SDL
} // namespace InputCommon
