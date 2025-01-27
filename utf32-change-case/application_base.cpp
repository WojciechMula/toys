class ApplicationBase {
    std::vector<std::string> procedure;
    std::vector<std::string> testcase;

protected:
    function_names_t fn_names;
    std::vector<Testcase> testcases;

public:
    ApplicationBase(std::vector<std::string> procedure, std::vector<std::string> testcase)
        : procedure{procedure}
        , testcase{testcase}
        , fn_names(function_names())
        , testcases{load_testcases("datasets")} {}

protected:
    bool can_run_testcase(const Testcase& tc) const {
        for (const auto& frag: testcase) {
            if (tc.utf32.name().find(frag) == std::string::npos) {
                return false;
            }
        }

        return true;
    }

    bool can_run_procedure(const std::string& name) const {
        for (const auto& frag: testcase) {
            if (name.find(frag) == std::string::npos) {
                return false;
            }
        }

        return true;
    }
};
