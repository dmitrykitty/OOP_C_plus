#include <iostream>


enum request_method {
    // обрабатываемые методы
    method_get = 1,
    method_post = 2,
    method_put = 3,
    method_delete = 4
};

struct Request {
    // объект запроса
    request_method method{method_get};
    std::string url;
    std::string data;
};

class RetriveMixin {
    request_method method{method_get};

public:
    RetriveMixin(request_method *ms, int index) { ms[index] = method; }
    virtual ~RetriveMixin() {}
    std::string get(const Request &request) { return "GET: " + request.url; }
};

class CreateMixin {
    request_method method{method_post};

public:
    CreateMixin(request_method *ms, int index) { ms[index] = method; }
    virtual ~CreateMixin() {}
    std::string post(const Request &request) { return "POST: " + request.url; }
};

class UpdateMixin {
    request_method method{method_put};

public:
    UpdateMixin(request_method *ms, int index) { ms[index] = method; }
    virtual ~UpdateMixin() {}
    std::string put(const Request &request) { return "PUT: " + request.url; }
};

class GeneralView : public RetriveMixin, public CreateMixin {
    enum { max_methods = 4 };

    int count_methods{0};
    request_method allowed_methods[max_methods]{method_get, method_post};

    bool is_method_exist(request_method method) const {
        for (int i = 0; i < count_methods; i++)
            if (method == allowed_methods[i])
                return true;
        return false;
    }

public:
    GeneralView(): RetriveMixin(allowed_methods, 0), CreateMixin(allowed_methods, 1) {}

    std::string render_request(const Request &request) const {
        return is_method_exist(request.method) ? request.method() : "";
    }
};

int main() {
    GeneralView gw;

    std::string res =  gw.render_request(Request(method_post,
                              "https://proproprogs.ru/cpp_oop/cpp-oop-mnozhestvennoe-nasledovanie-poryadok-vyzova-konstruktorov-i-destruktorov",
                              "<h1>Множественное наследование</h1>"));
    std::cout << res << std::endl;
}
