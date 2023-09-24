#include "crow.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([]() {
        return "Hello world";
    });

    CROW_ROUTE(app, "/")([]() {

        std::string vec[3];

        vec[0] = "asdf";
        vec[1] = "asdf";
        vec[2] = "asdf";

        crow::response res;
        res.set_header("Content-Type", "text/plain");

        // Join the strings from the array into a single string
        std::string result;
        for (const std::string &str: vec) {
            result += str + "\n";
        }

        res.write(result);
        return res;
    });


    CROW_ROUTE(app, "/hello/<int>")
            ([](int count) {
                if (count > 100)
                    return crow::response(400);
                std::ostringstream os;
                os << count << " bottles of beer!";
                return crow::response(os.str());
            });

    app.port(18080).multithreaded().run();
}