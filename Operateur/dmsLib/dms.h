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

	dms& operator + (const dms& my_dms) {
		int test_secondes = *secondes + *(my_dms.getDegre());
		int test_minutes = 0;
		if (test_secondes > 60) {
			setSecondes(test_secondes % 60);
			test_minutes = 1;
		}
		test_minutes = *minutes + *(my_dms.getMinutes()) + test_minutes;
		if (test_minutes > 60) {
			setMinutes(test_minutes % 60);
			setDegre(*degre + 1);
		}
		setDegre(*degre + *(my_dms.degre));

		return *this;
	}

	dms& operator - (const dms& my_dms) {
		int 
	}



};

