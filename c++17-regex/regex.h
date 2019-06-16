#include <regex>
#include <string_view>

namespace nonstd {

class regex {
protected:
    std::regex re;

protected:
    using sv_match = std::match_results<std::string_view::const_iterator>;

    struct regex_iter {
        sv_match& match;
        int index;
        regex_iter(sv_match& match_, int index_) : match(match_), index(index_) {}

        bool operator!=(const regex_iter& it) const noexcept {
            if (&match == &it.match)
                return index != it.index;
            else    
                return true;
        }

        regex_iter& operator++() noexcept {
            index += 1;
            return *this;
        }

        std::string_view operator*() const {
            const auto f = match[index].first;
            const auto l = match[index].second;

            return std::string_view(f, static_cast<std::string_view::size_type>(l - f));
        }
    };

    struct regex_match {
        sv_match match;
        regex_match(sv_match&& match_) : match(match_) {}

        regex_iter begin() {
            if (match.size() > 0)
                return regex_iter(match, 1);
            else
                return regex_iter(match, 0);
        }
        
        regex_iter end() {
            return regex_iter(match, match.size());
        }
    };

public:
    regex() = delete;
    regex(const regex&) = default;
    regex(regex&&) = default;
    regex& operator=(const regex&) = default;
    regex& operator=(regex&&) = default;
    ~regex() = default;

public:
    regex(const std::regex& re_) : re(re_) {}
    regex(std::regex&& re_) : re(std::move(re_)) {}

    bool match(const std::string_view sv,
               std::regex_constants::match_flag_type = std::regex_constants::match_default) const
    {
        sv_match match;
        return std::regex_match(sv.begin(), sv.end(), match, re);
    }

    regex_match iter(const std::string_view sv,
                     std::regex_constants::match_flag_type = std::regex_constants::match_default) const
    {
        sv_match match;
        std::regex_match(sv.begin(), sv.end(), match, re);
        return regex_match(std::move(match));
    }
};

} // namespace nonstd
