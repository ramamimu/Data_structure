# Practice
* ## Problem 1
  Make a program to check whether a string is a palindrome or not by implementing the **Stack** data structure.
  
  **Input Example 1**
  
  <dl>
    <pre>kasur_rusak</pre>
  </dl>

  **Output Example 1**
  
  <dl>
    <pre>palindrom</pre>
  </dl>

  **Input Example 2**
  
  <dl>
    <pre>macbook pro</pre>
  </dl>

  **Output Example 2**
  
  <dl>
    <pre>mahal, eh bukan palindrom deh</pre>
  </dl>

* ## Problem 2
  A TC Clinic is currently serving a queue of patients. Every patient has an **id** and an **urgency level** that are represented by a number. Make a program to simulate how the queue goes on that clinic!
  ### Input
  The first line is Q, the amount of queries. Every query can consist of:
  * `MASUK id x` - id is the id of a patient and x is the level of urgency.
  * `LAYANI` - print the id of the patient that is currently being attended to.
  ### Output
  For every `LAYANI` query, print the id of the patient that is currently being attended to. If there are no more patients in queue, print "HORE".

  **Input Example**
  <pre>
  9
  MASUK 1 15
  MASUK 3 2
  MASUK 2 6
  MASUK 7 15
  LAYANI
  LAYANI
  MASUK 8 100
  LAYANI
  LAYANI
  </pre>
  **Output Example**
  <pre>
  1
  7
  8
  2
  </pre>

* ## Problem 3
  Modify the given Stack, Queue, Deque, and Priority Queue so that they can store a string with maximum of 100 characters.