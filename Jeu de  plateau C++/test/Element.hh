#ifndef ELEMENT_HH
#define ELEMENT_HH

#include <string>

class Element{

	public :
		Element();
		Element(std::string nom);
		~Element();
		std::string GetNom();
		void SetNom(std::string nom);
        void SetPos(int x, int y);
        int Getx();
        int Gety();
    public:
		std::string nom ;
        int x ;
        int y ;



};

#endif // ELEMENT_HH
