#pragma once

#include "shared.hpp"
#include <optional>

namespace intercept::search {
    class plugin_searcher {
    public:
        plugin_searcher();
        //This is here because it's easier to crossplatform n stuff
        static std::string get_command_line();
    #if defined(_WIN32) || defined(_WIN64)
        std::optional<std::wstring> find_extension(const std::wstring& name);
    #else
        std::optional<std::string> find_extension(const std::string& name);
    #endif
        
        
    private:
    #if defined(_WIN32) || defined(_WIN64)
        static std::vector<std::wstring> generate_pbo_list();
        std::vector<std::wstring> active_mod_folder_list;
    #else
        static std::vector<std::string> generate_pbo_list();
        std::vector<std::string> active_mod_folder_list;
    #endif
    };
}
