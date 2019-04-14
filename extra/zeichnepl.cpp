#include <iostream>
#include <string>
#include <vector>
#include "Point.h"
#include "Line.h"
#include "ooptool.h"
#include "ooptoolg.h"

using namespace std;

Canvas cvs;
vector<sf::Color> colors;
void init_colors() {
    // won't work with static initializer list globally (all colors are black)
    // const initialization apparently too late as not inline
    colors.push_back(Rot);
    colors.push_back(Gruen);
    colors.push_back(Blau);
    colors.push_back(Gelb);
    colors.push_back(Magenta);
    colors.push_back(Cyan);
}

ostream &show_color(ostream &out, sf::Color color) {
    out << "Color(r=" << (int) color.r << ", g=" << (int) color.g <<
        ", b=" << (int) color.b << ")";
    return out;
}

void draw_points() {
    cvs.add_text(600, 0, "draw_points");
    // show_color(cout, colors[0]) << endl;
    Point points[] = { {10, 10}, {100, 10}, {10, 100} };
    int handles[sizeof(points)/sizeof(Point)];
    for (size_t i=0; i < sizeof(handles)/sizeof(int); i+=1) {
        int x = points[i].get_x();
        int y = points[i].get_y();
        sf::Color color = colors[i];
        handles[i] = cvs.add_circle(x, y, 10, color);
                          
    }
    Point vec = {2, 1};
    for (size_t j=0; j < 256; j+=1) {
        for (size_t i=0; i < sizeof(points)/sizeof(Point); i+=1) {
            points[i] += vec;
            cvs.move_to(handles[i], points[i].get_x(), points[i].get_y());
        }
        schlafeMs(17);
    }
    schlafeMs(2000);
    cvs.clear();
}

void draw_lines() {
    cvs.add_text(600, 0, "draw_lines");
    int error = cvs.add_text(0, 350, "", 24, Rot);
    Point middle { 20, 20 };
    vector<Line> lines;
    vector<int> handles;
    int diffx = 40;
    int diffyfak = 6;
    for (size_t i=0; i < colors.size(); i+=1) {
        Point other { middle.get_x()+diffx,
                middle.get_y() + (diffyfak * ((int) i)) };
        Line line { middle, other };
        lines.push_back(line);
        Point start = line.get_start();
        Point end = line.get_end();
        int handle = cvs.add_line(start.get_x(), start.get_y(),
                                  end.get_x(), end.get_y(),
                                  colors[i%colors.size()], 1);
        handles.push_back(handle);
    }
    Point vec = {2, 1};
    for (size_t j=0; j < 256; j+=1) {
        for (size_t i=0; i < lines.size(); i+=1) {
            lines[i] += vec;
            int startx = lines[i].get_start().get_x();
            int starty = lines[i].get_start().get_y();
            cvs.move_to(handles[i], startx, starty);
            // just start is sufficient, as the end cannot be
            // manipulated otherwise. However, we check manually...
            int endx = lines[i].get_end().get_x();
            int endy = lines[i].get_end().get_y();
            int expected_diffy = (diffyfak * ((int) i));
            if (endx - startx != diffx) {
                string errmsg = "ERROR :";
                errmsg += "startx=" + to_string(startx);
                errmsg += ", endx=" + to_string(endx);
                errmsg += " has difference != " + to_string(diffx);
                cerr << errmsg << endl;
                cvs.change_text(error, errmsg);
                schlafeMs(510);
            } else if (endy - starty != expected_diffy) {
                string errmsg = "ERROR :";
                errmsg += "starty=" + to_string(starty);
                errmsg += ", endy=" + to_string(endy);
                errmsg += " has difference != " + to_string(expected_diffy);
                cerr << errmsg << endl;
                cvs.change_text(error, errmsg);
                schlafeMs(510);
            } else {
                cvs.change_text(error, "");
            }
        }
        schlafeMs(17);
    }
    schlafeMs(2000);
    cvs.clear();
}

int main(int argc, const char *argv[]) {
    argsp_t argsp(argc, argv);
    init_colors(); 
    if (!argsp.flag("skip-points")) {
        draw_points();
    }
    if (!argsp.flag("skip-lines")) {
        draw_lines();
    }
    if (!argsp.flag("skip-done")) {
        cvs.add_text(600, 0, "done");
        cvs.quit(1000); // max wait
    }
}
