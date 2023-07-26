#pragma once

#include <boost/system/error_code.hpp>
#include <boost/system/result.hpp>
#include <cstdint>
#include <fmt/format.h>

namespace core {

enum class ErrorCode {
    SUCCESS = 0,
    ZERO_DENOMINATOR,
};

// Custom category that maps MyErr->std::string
struct Category : std::error_category {
    const char *name() const noexcept override { return "Category"; }
    std::string message(int condition) const override {
        switch (condition) {
        case 0:
            return "Sucess";
        case 1:
            return "Denominator is zero";
        }
        return "";
    }
};

inline std::string getErrorStr(std::error_code const &e) { return e.category().message(e.value()); }

inline std::error_code make_error_code(ErrorCode e) { return std::error_code(fmt::underlying(e), Category()); }
template <typename T> using expected = boost::system::result<T, std::error_code>;

inline auto success = boost::system::result<void, std::error_code>{};
} // namespace core

// Register our enum as an error code
// so we can constructor error_code from it
template <> struct std::is_error_code_enum<core::ErrorCode> : public std::true_type {};