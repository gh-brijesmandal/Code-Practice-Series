#[warn(dead_code)]
struct Person<PetType: Animal>{    // declared a generic that is not bounded to any data type and contains everything, // bounded PetType to Animal
    owner: String,
    pet: PetType,
}


// lets declare a trait so that PetType can be bounded to certain pets and that the code does not get repetitive

trait Animal {
    fn sound(&self);  // declared a method that will be used by every binded struct, takes a reference of the data type and prints the resulting sound
} 
// this trait works as abstraction in C++ where we sign a contract with it and if a contract is signed, we have to use its methods
#[warn(dead_code)]
struct Dog; // declared an empty struct Dog 
#[warn(dead_code)]
struct Cat;  // declared an empty struct for Cat
#[warn(dead_code)]
struct Tiger; // declared an empty struct for Tiger Data Type
#[warn(dead_code)]
struct Bear;  // declared an empty struct for Bear Data Type

// lets add a trait to each of them so that they get linked with the PetType 
impl Animal for Dog {
    fn sound(&self){
        println!("Dog is barking.");
    }
}
impl Animal for Cat {
    fn sound(&self){
        println!("Cat is meowing.");
    }    
}
impl Animal for Tiger {
    fn sound(&self){
        println!("Tiger is roaring.");
    }    
}
impl Animal for Bear {
    fn sound(&self){
        println!("Bear is skadousssh."); // i know no one see my code so I am safe
    }    
}


fn main() {
    let brijes: Person<Cat> = Person{ 
        owner: "Brijes Mandal".to_string(),
        pet: Cat,
    };
    brijes.pet.sound();
}