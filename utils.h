#pragma once

#define PRINT_CONTAINER(expr) for (auto item : (expr)) std::cout << item << ", "; std::cout <<"\n";