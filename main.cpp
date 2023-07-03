#include <string>
#include <iostream>

class Cold_Blooded {
private:
	std::string body_temperature_dependency;
	std::string metabolism;
	std::string skin_covering;
	virtual void cln_vrt() = 0;
public:
	Cold_Blooded() {
		this->body_temperature_dependency = "dependent";
		this->metabolism = "low";
	}
	Cold_Blooded(std::string skin_covering, std::string moving_type) {
		std::cout << "Cold blooded param" << std::endl;
		this->body_temperature_dependency = "dependent";
		this->metabolism = "low";
		this->set_skin_covering(skin_covering);
	}
	void set_skin_covering(std::string skin_cover) {
		if (skin_cover == "dry scales" || skin_cover == "wet scales" || skin_cover == "moist") {
			this->skin_covering = skin_cover;
		}
	}
	
std::string get_body_temperature_dependency() {
	return this->body_temperature_dependency;
}
std::string get_metabolism() {
	return this->metabolism;
}
std::string get_skin_covering() {
	return this->skin_covering;
}
};


class Fish : public virtual Cold_Blooded {
	std::string type;
	std::string skin_type;
public:
	Fish(std::string type, std::string skin_type){
		this->set_type(type);
		this->set_skin_type(skin_type);
	}
	void set_type(std::string type) {
		this->type = type;
	}
	void set_skin_type(std::string skin_type) {
		if (skin_type == "wet") {
			this->skin_type = skin_type;
		}
	}
	void cln_vrt() override {
		std::cout << std::endl;
	}
	std::string get_skin_type() {
		return this->skin_type;
	}
	std::string get_type() {
		return this->type;
	}
};

class Reptile : public virtual Cold_Blooded {
	std::string type;
	std::string type_of_breath;
	std::string moving_type;
	int heart_chamber_count;
	void cln_vrt() override {
		std::cout << std::endl;
	}
public:

	Reptile(std::string type, std::string type_of_breath, int chamber_count) {
		this->set_type_of_breath(type_of_breath);
		this->set_type(type);
		this->set_heart_chamber_count(chamber_count);
	}
	Reptile(std::string type_of_breath, int chamber_count) {
		this->set_type_of_breath(type_of_breath);
		this->set_heart_chamber_count(chamber_count);
	}
	void set_type(std::string type) {
		this->type = type;
	}
	void set_type_of_breath(std::string breath) {
		if (breath == "lungs" || breath == "lungs and sacs" || breath == "gills") {
			this->type_of_breath = breath;
		}
	}
	void set_heart_chamber_count(int count) {
		if (count >= 2 && count <= 4) {
			this->heart_chamber_count = count;
		}
	}
	void set_moving_type(std::string move) {
		if (move == "walking and crawling"
			|| move == "swimming and walking"
			|| move == "swimming and crawling"
			|| move == "swimming and crawling or walking"){
			this->moving_type = move;
		}
	}
	std::string get_type_of_breath() {
		return this->type_of_breath;
	}

	std::string get_moving_type() {
		return this->moving_type;
	}

	int get_heart_chamber_count() {
		return this->heart_chamber_count;
	}	
};


class Amphibian : public Fish, public Reptile {
	std::string additional_breath;
public:
	void set_additional_breath(std::string breath) {
		this->additional_breath = breath;
	}
	std::string get_additional_breath() {
		return this->additional_breath;
	}
	Amphibian(std::string type) : Fish(type, "wet"), Reptile("lungs", 3) {
		this->set_additional_breath("skin");
		this->set_moving_type("swimming and crawling or walking");
	}
	void print_data() {
		std::cout << "Type: " << this->get_type() << ";" << std::endl;
		std::cout << "Body temperature: " << this->get_body_temperature_dependency() << ";" << std::endl;
		std::cout << "Metabolysm level: " << this->get_metabolism() << ";" << std::endl;
		std::cout << "Skin type: " << this->get_skin_type() << ";" << std::endl;
		std::cout << "Type of breath: " << this->get_type_of_breath() << ";" << std::endl;
		std::cout << "Additional breath: " << this->get_additional_breath() << ";" << std::endl;
		std::cout << "Type of moving: " << this->get_moving_type() << ";" << std::endl;
		std::cout << "Heart type: " << this->get_heart_chamber_count() << " chambered;" << std::endl;
	}
protected:
	void cln_vrt() override {
		std::cout << std::endl;
	}
};

int main() {

	Amphibian a("frog");
	a.print_data();

	return 0;
}