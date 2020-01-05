# Knapsack
<b>Εργασία στο μάθημα “Αλγόριθμοι και Προχωρημένες Δομές Δεδομένων” - Διερεύνηση προσεγγίσεων επίλυσης του προβλήματος 0-1 σακιδίου</b>
<p><p><b>ΣΗΜΕΙΩΣΗ</b>: Οι δυο προσεγγίσεις επίλυσης με τους επιλυτές OR-TOOLS δεν κατάφεραν να τρέξουν ούτε σε Linux αλλά ούτε και σε Windows περιβάλλον, με συνέπεια οι μέθοδοι που παρουσιάζονται στο παρόν repository να είναι οι 4 πρώτοι, δηλ: Dynamic Programming, Greedy Approach, Brute Force και Branch and Bound.
<p>Για να διερευνήσουμε τις προσεγγίσεις επίλυσης του προβλήματος που μας έχει ανατεθεί πρέπει πρώτα να φτιαχτούν τα αρχεία (στιγμιότυπα) των προβλημάτων με τον generator που μας δόθηκε. 
Κατεβάζουμε το generator.c από τη διεύθυνση http://hjemmesider.diku.dk/~pisinger/generator.c και το κάνουμε compile (g++ -o generator generator.c) σε ένα terminal στο linux.
Φτιάχνουμε ένα linux bash file <b>(makefiles)</b> το οποίο αφού αλλάξουμε τα δικαιώματά του (αν χρειατεί, γράφοντας chmod +x makefiles) το τρέχουμε (./makefiles) και παράγουμε τα 320 αρχεία με βάση την ονοματολογία που μας ζητήθηκε.
<p>Τα αρχεία (στιγμιότυπα) αυτά βρίσκονται διαθέσιμα στον φάκελο <b>Problems</b>.
Τα στιγμιότυπα αυτά πρέπει να μπουν όλα μαζί σε ένα directory μαζί με τον κώδικα <b>(Knapsack-Code.cc)</b> από το οποίο θα τρέξει ως εξής:
<p> Κάνουμε αρχικά compile το <b>Knapsack-Code.cc</b> γράφοντας σε ένα linux terminal (g++ --std+C++11 -o runfile Knapsack-Code.cc) και έπειτα το τρέχουμε γράφοντας (./runfile).
<p>  
Όταν ολοκληρωθεί η εκτέλεση του προγράμματος παράγεται ένα .csv αρχείο με τα αποτελέσματα τις κάθε μεθόδου. Tο αρχείο αυτό είναι διαθέσιμο με το όνομα <b>results.csv</b>
