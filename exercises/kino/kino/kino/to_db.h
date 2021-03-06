#ifndef TO_DB_H_
#define TO_DB_H_

#include <map>
#include <string>
#include <vector>
#include "film.h"
#include "sala.h"
#include "seans.h"
#include "klient.h"
#include "rezerwacja.h"

class Film;

using	std::map;
using   std::vector;
typedef std::string str;

class To_DB
{
public:
	virtual map<str, str> create_table_map()			const = 0;
	virtual map<str, str> add_record_map()				const = 0;
	virtual map<str, str> up_record_map(unsigned int)	const = 0;
	static unsigned int error_nr;
};

class Rezerwacje_to_DB : public To_DB
{
public:
	const static str COLUMN_NAME_REZERWACJE;
	Rezerwacje_to_DB() = default;
	virtual map<str, str> create_table_map()					const override;
	virtual map<str, str> add_record_map()						const override;
	virtual map<str, str> up_record_map(unsigned int kolumna)	const override { map<str, str> e; return e; }//todo}
	void set_rezerwacje(const Rezerwacje* rezerwacje_ptr);
private:
	static const unsigned int NUMBER_OF_COLUMNS = 3;
	enum columns { _ID, Rezerwacja_ID, Klient_ID };					// size 5
	const static vector<str> column_names;							// names vector size must be equal to atributes vecotr size
	const static vector<str> column_atributes;
	const Rezerwacje* ptr_to_rezerwacje;						
};

class Rezerwacja_to_DB : public To_DB
{
public:
	const static str COLUMN_NAME_REZERWACJA;
	Rezerwacja_to_DB() = default;
	virtual map<str, str> create_table_map()					const override;
	virtual map<str, str> add_record_map()						const override;
	virtual map<str, str> up_record_map(unsigned int kolumna)	const override { map<str, str> e; return e; }//todo}
	void set_rezerwacja(const Rezerwacja* rezerwacja_ptr);
private:
	static const unsigned int NUMBER_OF_COLUMNS = 3;
	enum columns { _ID, Seans_ID, Oplacona };						// size 3
	const static vector<str> column_names;							// names vector size must be equal to atributes vecotr size
	const static vector<str> column_atributes;
	const Rezerwacja* ptr_to_rezerwacja;							
};

class Klient_to_DB : public To_DB
{
public:
	const static str COLUMN_NAME_KLIENT;
	Klient_to_DB() = default;
	virtual map<str, str> create_table_map()					const override;
	virtual map<str, str> add_record_map()						const override;
	virtual map<str, str> up_record_map(unsigned int kolumna)	const override { map<str, str> e; return e; }//todo}
	void set_klient(const Klient* klient_ptr);
private:
	static const unsigned int NUMBER_OF_COLUMNS = 3;
	enum columns { _ID, Imie, Nazwisko };					// size 5
	const static vector<str> column_names;					// names vector size must be equal to atributes vecotr size
	const static vector<str> column_atributes;
	const Klient* ptr_to_klient;								
};

class Seans_to_DB : public To_DB
{
public:
	const static str COLUMN_NAME_SEANS;
	Seans_to_DB() = default;
	virtual map<str, str> create_table_map()					const override;
	virtual map<str, str> add_record_map()						const override;
	virtual map<str, str> up_record_map(unsigned int kolumna)	const override;
	void set_seans(const Seans* seans_ptr);
	enum columns { _ID, Data, Sala, Film, Zajete };
private:
	static const unsigned int NUMBER_OF_COLUMNS = 5;
					// size 5
	const static vector<str> column_names;							// names vector size must be equal to atributes vecotr size
	const static vector<str> column_atributes;
	const Seans* ptr_to_seans;									
};


class Sala_to_DB : public To_DB
{
public:
	const static str COLUMN_NAME_SALA;
	Sala_to_DB() = default;
	Sala_to_DB(const Sala* sala_ptr) : ptr_to_sala(sala_ptr) {}
	virtual map<str, str> create_table_map()					const override;
	virtual map<str, str> add_record_map()						const override;
	virtual map<str, str> up_record_map(unsigned int kolumna)	const override { map<str, str> e; return e; }//todo}
	void set_sala(const Sala* sala_ptr);
	
private:
	static const unsigned int NUMBER_OF_COLUMNS = 2;
	enum columns {_ID, Wielkoscs};						// size 2
	const static vector<str> column_names;				// names vector size must be equal to atributes vecotr size
	const static vector<str> column_atributes;
	const Sala* ptr_to_sala;
};


class Film_to_DB : public To_DB
{
public:
	const static str COLUMN_NAME_FILM;
	Film_to_DB() = default;
	Film_to_DB(const Film* film_ptr) : ptr_to_film(film_ptr) {}
	virtual map<str, str> create_table_map()					const override;
	virtual map<str, str> add_record_map()						const override;
	virtual map<str, str> up_record_map(unsigned int kolumna)	const override;
	void set_film(const Film* film_ptr);
private:
	static const unsigned int NUMBER_OF_COLUMS = 4;
	enum columns { _ID, Tytul, Dlugosc, Gatunek };		// size 4
	const static vector<str> column_names;				// names vector size must be equal to atributes vecotr size
	const static vector<str> column_atributes;
	const Film* ptr_to_film;
};

#endif // !TO_DB_H_
