#ifndef REGISTRY_FACTORY_H_
#define REGISTRY_FACTORY_H_

#include <map>
#include <string>
#include <ArduinoLog.h>
#include "DisableConstructors.h"

template<typename T>
class RegistryBase : NO_COPY, NO_MOVE {
public:
    virtual T *Create() = 0;

protected:
    RegistryBase() = default;

    virtual ~RegistryBase() = default;
};

template<typename T>
class RegisterFactory : NO_COPY, NO_MOVE {
public:
    inline static RegisterFactory &Instance() {
        static RegisterFactory _;
        return _;
    }

    inline void Register(const std::string &type_name, RegistryBase<T> *registry) {
        registry_[type_name] = registry;
    }

    [[maybe_unused]] inline T *Create(const std::string &type_name) {
        return registry_.find(type_name) != registry_.end() ? registry_[type_name]->Create() : nullptr;
    }

private:
    RegisterFactory() = default;

    ~RegisterFactory() = default;

    std::map<std::string, RegistryBase<T> *> registry_;
};

template<typename B, typename T>
class Registry final : public RegistryBase<B> {
public:
    [[maybe_unused]] explicit Registry(const std::string &type_name) {
        RegisterFactory<T>::Instance().Register(type_name, this);
    }

    [[maybe_unused]] inline B *Create() final { return new T(); }
};

#endif  // REGISTRY_FACTORY_H_
