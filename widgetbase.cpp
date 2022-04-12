#include "widgetbase.hpp"

WidgetBase::WidgetBase(WindowBase *mainw, int posx, int posy, int sizex, int sizey, std::string name) : _mainw(mainw), _posx(posx), _posy(posy), _sizex(sizex), _sizey(sizey), _name(name) { }

WidgetBase::~WidgetBase() { }
