#pragma once
class dms
{
private:
	int* degre;
	int* minutes;
	int* secondes;
	dms& operator=(const dms& my_dms) {
		if (this == &my_dms) {
			return *this;
		}

		delete degre;
		delete minutes;
		delete secondes;

		degre = new int(*(my_dms.degre));
		minutes = new int(*(my_dms.minutes));
		secondes = new int(*(my_dms.secondes));

		return *this;
	}

public:

	dms() {
		degre = new int(0);
		minutes = new int(0);
		secondes = new int(0);
	}

	dms(int my_degre, int my_minutes, int my_secondes) {
		degre = new int(my_degre);
		minutes = new int(my_minutes);
		secondes = new int(my_secondes);
	}

	dms(const float my_degre) {
		degre = new int();
		minutes = new int();
		secondes = new int();
		*degre = (int)my_degre;
		float floatMinutes = (my_degre - (float)((int)my_degre)) * 100;
		*minutes = (int)(floatMinutes);
		*secondes = (int)((floatMinutes - (float)((int)floatMinutes)) * 100);
	}

	~dms() {
		delete degre;
		delete minutes;
		delete secondes;
	}

	int* getDegre() const {
		return degre;
	}

	int* getMinutes() const {
		return minutes;
	}

	int* getSecondes() const {
		return secondes;
	}

	void setDegre(int nb) {
		*degre = nb;
	}

	void setMinutes(int nb) {
		*minutes = nb;
	}

	void setSecondes(int nb) {
		*secondes = nb;
	}

	dms(const dms& my_dms) {
		degre = new int(*(my_dms.degre));
		minutes = new int(*(my_dms.minutes));
		secondes = new int(*(my_dms.secondes));
	}

	dms operator + (const dms& my_dms) {
		dms *res = new dms();
		int test_secondes = *secondes + *(my_dms.getDegre());
		int test_minutes = 0;
		if (test_secondes > 60) {
			res->setSecondes(test_secondes % 60);
			test_minutes = 1;
		}
		int test_degre = 0;
		test_minutes = *minutes + *(my_dms.getMinutes()) + test_minutes;
		if (test_minutes > 60) {
			res->setMinutes(test_minutes % 60);
			test_degre = 1;
		}
		res->setDegre(*degre + *(my_dms.degre) + test_degre);

		return *res;
	}

	dms operator - (const dms& my_dms) {
		dms *res = new dms();
		int test_degre = *degre - *(my_dms.getDegre());
		if (test_degre < 0) {
			res->setDegre(0);
			res->setMinutes(0);
			res->setSecondes(0);
		}
		else {
			res->setDegre(test_degre);
		}
		int test_minutes = *minutes - *(my_dms.getMinutes());
		if (test_minutes < 0) {
			res->setMinutes(0);
			res->setSecondes(0);
		}
		else {
			res->setMinutes(test_minutes);
		}
		int test_secondes = *secondes - *(my_dms.getMinutes());
		if (test_secondes < 0) {
			res->setSecondes(0);
		}
		else
		{
			res->setSecondes(test_secondes);
		}
		return *res;
	}

	dms operator * (const unsigned int nb) {
		dms* res = new dms();
		int test_secondes = *secondes * nb;
		int test_minutes = 0;
		if (test_secondes > 60) {
			res->setSecondes(test_secondes % 60);
			test_minutes = test_secondes / 60;
		}
		int test_degre = 0;
		test_minutes = (*minutes + test_minutes) * nb;
		if (test_minutes > 60) {
			res->setMinutes(test_minutes % 60);
			test_degre = test_minutes / 60;
		}
		res->setDegre((test_degre + *degre) * nb);

		return *res;
	}

	float operator ^ (const dms& my_dms) {
		float res = (float)*(my_dms.getDegre()) + (float)*(my_dms.getMinutes()) * 100.0 / 60.0 + (float)*(my_dms.getSecondes()) * 1000 / 60;
		return res;
	}

	bool operator <= (const dms& my_dms) const {
		if (getDegre() == my_dms.getDegre()) {
			if (getMinutes() == my_dms.getMinutes()) {
				return getSecondes() <= my_dms.getSecondes();
			}
			else {
				return getMinutes() <= my_dms.getMinutes();
			}
		}
		else {
			return getDegre() <= my_dms.getDegre();
		}

	}


	bool operator >= (const dms& my_dms) const {
		if (*(getDegre()) == *(my_dms.getDegre())) {
			if (*(getMinutes()) == *my_dms.getMinutes()) {
				return *getSecondes() >= *my_dms.getSecondes();
			}
			else {
				return *getMinutes() >= *my_dms.getMinutes();
			}
		}
		else {
			return *getDegre() >= *my_dms.getDegre();
		}

	}

	bool operator == (const dms& my_dms) const {
		return *getDegre() == *my_dms.getDegre() && *getMinutes() == *my_dms.getMinutes() && *getSecondes() == *my_dms.getSecondes();
	}

	bool operator != (const dms& my_dms) const {
		return *getDegre() != *my_dms.getDegre() || *getMinutes() != *my_dms.getMinutes() || *getSecondes() != *my_dms.getSecondes();
	}




};

