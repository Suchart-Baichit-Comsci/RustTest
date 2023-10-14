use std::io;

fn main() {
    let mut lab_score = String::new();
    let mut exam_score = String::new();

    println!("Enter lab score: ");
    io::stdin().read_line(&mut lab_score).expect("Failed to read line");
    let lab_score: f64 = lab_score.trim().parse().expect("Please enter a valid number");

    println!("Enter exam score: ");
    io::stdin().read_line(&mut exam_score).expect("Failed to read line");
    let exam_score: f64 = exam_score.trim().parse().expect("Please enter a valid number");

    let total_score = (lab_score * 0.4 + exam_score * 0.6);

    let grade = match total_score {
        x if (80.0..=100.0).contains(&x) => "A",
        x if (75.0..=79.9).contains(&x) => "B+",
        x if (70.0..=74.9).contains(&x) => "B",
        x if (65.0..=69.9).contains(&x) => "C+",
        x if (60.0..=64.9).contains(&x) => "C",
        x if (55.0..=59.9).contains(&x) => "D+",
        x if (50.0..=54.9).contains(&x) => "D",
        _ => "F",
    };

    println!("Grade: {}", grade);
}
use std::io;

fn main() {
    let mut lab_score = String::new();
    let mut exam_score = String::new();

    println!("Enter lab score: ");
    io::stdin().read_line(&mut lab_score).expect("Failed to read line");
    let lab_score: f64 = lab_score.trim().parse().expect("Please enter a valid number");

    println!("Enter exam score: ");
    io::stdin().read_line(&mut exam_score).expect("Failed to read line");
    let exam_score: f64 = exam_score.trim().parse().expect("Please enter a valid number");

    let total_score = (lab_score * 0.4 + exam_score * 0.6);

    let grade = match total_score {
        x if (80.0..=100.0).contains(&x) => "A",
        x if (75.0..=79.9).contains(&x) => "B+",
        x if (70.0..=74.9).contains(&x) => "B",
        x if (65.0..=69.9).contains(&x) => "C+",
        x if (60.0..=64.9).contains(&x) => "C",
        x if (55.0..=59.9).contains(&x) => "D+",
        x if (50.0..=54.9).contains(&x) => "D",
        _ => "F",
    };

    println!("Grade: {}", grade);
}
