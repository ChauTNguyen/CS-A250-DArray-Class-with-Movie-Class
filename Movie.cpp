#include "Movie.h"

Movie::Movie()
{
	movieTitle = "N/A";
	productionYear = 0;
}

Movie::Movie(const string& newMovieTitle, int newProductionYear)
{
	movieTitle = newMovieTitle;
	productionYear = newProductionYear;
}

ostream& operator<<(ostream& out, const Movie& movie)
{
	out << "Movie Title: " << movie.movieTitle << endl
		<< "Production Year: " << movie.productionYear << endl;
	return out;
}

void Movie::printMovieDetails() const
{
	cout << "Movie Title: " << movieTitle << "; Production Year: " << productionYear << endl;
}

string Movie::getMovieTitle() const
{
	return movieTitle;
}

int Movie::getProductionYear() const
{
	return productionYear;
}

void Movie::setMovieTitle(const string& newMovieTitle)
{
	movieTitle = newMovieTitle;
}

void Movie::setProductionYear(int newProductionYear)
{
	productionYear = newProductionYear;
}

Movie::~Movie()
{

}