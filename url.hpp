#include <string>


class Url{
    private: 
    std::string url;
    static size_t handle_data(void*ptr, size_t size, size_t nmemb, void *stream);
    static std::string contents;

    public:
    Url(std::string url);

    std::string getContents();
};