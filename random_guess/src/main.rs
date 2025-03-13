use rand::Rng;
use std::io;
use colored::*;
use std::cmp::Ordering;

fn main()
{
    println!("Welcome to the random number guessing game.");
    loop{
        let secret_number = rand::rng().random_range(1..=10);
        println!("Guess a random number.");
        let mut guess: String = String::new();
        io::stdin()
            .read_line(&mut guess)
            .expect("Error");
        let guess:u8 = match guess.trim().parse()
        {
            Ok(num) => num,
            Err(_e) => 
            {
                println!("Enter a number!");
                continue;
            },
        };

        match guess.cmp(&secret_number){
            Ordering::Less => println!("{}","Too small number!".bright_red()),
            Ordering::Greater => println!("{}","Too large number!".bright_red()),
            Ordering::Equal => {
                println!("{}","You win!".green());
                break;
            },
        }
        println!("The secret number is {}\n", secret_number);
    }  
}
