///////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////

#include<stdlib.h>
#include<iostream>
#include"geohash_encoder.h"

using namespace sf1r_geohash;

int main(int argc, char** argv)
{
	GeoHashEncoder encode;
	if(argc != 4)
	{
		std::cout << "#===========================================================\n\n";
		std::cout << "Usage:geohash-encoder\n\n";
		std::cout << "      --longitude [-180.0 180]\n\n";
		std::cout << "      --latitude [-90.0 90.0]\n\n";
		std::cout << "      --length  [1 12] ps:geohash string length\n\n";
		std::cout << "#===========================================================\n";
		return 1;
	}
	std::string geohash = encode.Encoder(atof(argv[1]),
								atof(argv[2]),atoi(argv[3]));

	GeoHashNeighbors nearby = encode.GetNeighborsGrids(atof(argv[1]),
													   atof(argv[2]),
													   atoi(argv[3]));

	std::cout << "\n\n==================geohash demo===============================\n\n";
	std::cout << "CENTER    :" << geohash << std::endl;
	std::cout << "NORTH     :" << nearby.north << std::endl;
	std::cout << "SOUTH     :" << nearby.south << std::endl;
	std::cout << "WEST      :"  << nearby.west << std::endl;
	std::cout << "EAST      :"   << nearby.east << std::endl;
	std::cout << "NORTH EAST:" << nearby.north_east << std::endl;
	std::cout << "NORTH WEST:" << nearby.north_west << std::endl;
	std::cout << "SOUTH EAST:" << nearby.south_east << std::endl;
	std::cout << "SOUTH WEST:" << nearby.south_west << std::endl;
	std::cout << "\n\n==============================================================\n\n";
	return 0;
}
