#include "crow.h"
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

using json = nlohmann::json;

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([]() {
        return "Hello world";
    });

    CROW_ROUTE(app, "/json")([]() {

        // Create an array
        std::vector<std::string> names = {"Alice", "Bob", "Charlie", "test"};

        // Convert the array to JSON
        json jsonArray = names;

        // Print the JSON
        return jsonArray.dump();

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