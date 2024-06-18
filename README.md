# Hospital-Patient-Records-Management 🏥 
Welcome to the Hospital Patient Records Management system! This program helps hospital administrators manage patient records, query data, and obtain summary information. The data is stored in a structure array, and the array size is provided using command line arguments.

📋 Features
Populate Patient Records: Automatically generate random patient records for testing.
Print All Records: Display all patient records in a tabular format.
Summarize Records: Get a summary of patient records, including counts by department and severity.
Search by Family Name: Search for patients by their family name.
Check Structure Size: Display the size of the Patient structure.
🚀 Getting Started
Prerequisites
A C compiler (e.g., gcc)
An Ubuntu VM or any Unix-based system
Installation
Clone the repository:

bash
Copy code
git clone https://github.com/your-username/hospital-patient-records.git
cd hospital-patient-records
Compile the program:

bash
Copy code
gcc -o hospital main.c patient.c
Usage
Run the program with the desired number of records (between 6 and 19):

bash
Copy code
./hospital <number_of_records>
Menu Options
1. Print all patient records.
2. Summary of the patient records.
3. Search for all patients by Family Name.
4. Size of the structure.
5. Quit.
📁 Project Structure
main.c: The main file containing the program entry point and menu logic.
patient.c: Contains functions for populating, printing, summarizing, and searching patient records.
patient.h: Header file with the Patient structure definition and function prototypes.
📜 Example Output
Here's a glimpse of the program in action:

markdown
Copy code
Menu:
1. Print all patient records.
2. Summary of the patient records.
3. Search for all patients by Family Name.
4. Size of the structure.
5. Quit.

Enter your choice: 1

No   First   Family      Dept        Cost       Days       Severity
1    Emily   Smith       3           20         10         2
2    Liam    Patel       1           15         5          0
...
🤝 Contributing
Contributions are welcome! Please follow these steps:

Fork the repository.
Create a new branch: git checkout -b feature/your-feature
Commit your changes: git commit -m 'Add some feature'
Push to the branch: git push origin feature/your-feature
Submit a pull request.
📝 License
This project is licensed under the MIT License - see the LICENSE file for details.

🌟 Acknowledgments
Thanks to everyone who contributes to open-source projects and makes the world a better place!
Enjoy managing patient records efficiently! 🏥✨
