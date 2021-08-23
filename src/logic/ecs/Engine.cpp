//
// Created by goon on 16.07.2021.
//

#include "Engine.h"
#include "ComponentMapper.h"

Engine::Engine() {
    ComponentMapper::start();
}
