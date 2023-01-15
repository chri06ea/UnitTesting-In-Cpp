#pragma once

#include <functional>
#include <string>
#include <vector>
#include <optional>

static constexpr auto username_minimum_length = 3;

using std::nullopt;

template <typename T>
using Optional = std::optional<T>;

template <typename Model, typename ...Args>
using Predicate = std::function<bool(const Model& entity)>;

using String = std::string;

template <typename T>
using List = std::vector<T>;

using UserToken = String;
