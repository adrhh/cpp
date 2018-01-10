#include "person.h"

int Person::person_counter = 0;

Person::Person(const string& f, const string& s) : fname(f), sname(s)
{
	person_counter++;
	person_id = person_counter;
}

void Person::add_event(Event* e)
{
	e_list.push_back(e);
}

void Person::delete_event(Event* e)
{
	auto it = find(e_list.begin(), e_list.end(), e);
	if (it != e_list.end())
		e_list.erase(it);
}

void Person::show_events() const
{
	for (auto e : e_list)
		e->show();
}