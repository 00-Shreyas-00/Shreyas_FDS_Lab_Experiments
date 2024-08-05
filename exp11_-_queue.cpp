#include <iostream>
#include <queue>
#include <string>

using namespace std;

// Job structure to store job details
struct Job {
    int id;
    string description;

    Job(int jobId, const string& jobDesc) : id(jobId), description(jobDesc) {}
};

// JobQueue class to manage the job queue
class JobQueue {
private:
    queue<Job> jobQueue;
    int nextJobId;

public:
    JobQueue() : nextJobId(1) {}

    // Function to add a job to the queue
    void addJob(const string& description) {
        Job newJob(nextJobId++, description);
        jobQueue.push(newJob);
        cout << "Job added: " << newJob.id << " - " << newJob.description << endl;
    }

    // Function to delete a job from the queue
    void deleteJob() {
        if (jobQueue.empty()) {
            cout << "No jobs in the queue to delete." << endl;
        } else {
            Job job = jobQueue.front();
            jobQueue.pop();
            cout << "Job deleted: " << job.id << " - " << job.description << endl;
        }
    }

    // Function to display all jobs in the queue
    void displayJobs() const {
        if (jobQueue.empty()) {
            cout << "No jobs in the queue." << endl;
        } else {
            queue<Job> tempQueue = jobQueue;
            while (!tempQueue.empty()) {
                Job job = tempQueue.front();
                tempQueue.pop();
                cout << "Job ID: " << job.id << ", Description: " << job.description << endl;
            }
        }
    }
};

int main() {
    JobQueue jq;
    int choice;
    string description;

    do {
        cout << "\nJob Queue Menu\n";
        cout << "1. Add Job\n";
        cout << "2. Delete Job\n";
        cout << "3. Display Jobs\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore the newline character left in the buffer

        switch (choice) {
            case 1:
                cout << "Enter job description: ";
                getline(cin, description);
                jq.addJob(description);
                break;
            case 2:
                jq.deleteJob();
                break;
            case 3:
                jq.displayJobs();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
