#include <crow.h>
#include <iostream>

using namespace std;


int main()
{
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        auto page = crow::mustache::load_text("index.html");

        return page;
    });
    CROW_ROUTE(app, "/preview.txt")([](){
        crow::response rep;
        rep.set_static_file_info("preview.txt");

        return rep;
    });
    CROW_ROUTE(app, "/knight3.mp4")([](){
        crow::response rep;
        rep.set_static_file_info("knight3.mp4");

        return rep;
    });
    CROW_ROUTE(app, "/style.css")([](){
       crow::response rep;
       rep.set_static_file_info("style.css");
       
       return rep;
    });

    app.port(80).multithreaded().run();
}