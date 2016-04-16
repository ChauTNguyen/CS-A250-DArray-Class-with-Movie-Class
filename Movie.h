/*
Chau Nguyen
CS A250
April 13, 2016

In-class Exercise 6
*/

#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>

using namespace std;

class Movie
{
	friend ostream& operator<<(ostream& out, const Movie& movie);
public:
	Movie();
	Movie(const string& newMovieTitle, int newProductionYear);

	void printMovieDetails() const;

	string getMovieTitle() const;
	int getProductionYear() const;

	void setMovieTitle(const string& newMovieTitle);
	void setProductionYear(int newProductionYear);

	~Movie();

private:
	string movieTitle;
	int productionYear;
};

#endif