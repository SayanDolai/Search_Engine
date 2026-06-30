
        
# 🔍 Search Engine using Trie & Positional Inverted Index

A modular **Search Engine** implemented in **C++** that supports efficient document indexing and retrieval using advanced data structures and information retrieval techniques. The project demonstrates concepts such as **Trie**, **Positional Inverted Index**, **Phrase Search**, and **TF-IDF Ranking**.

---

## 🚀 Features

- 📂 Indexes multiple text documents.
- 🔎 Fast keyword search using a **Positional Inverted Index**.
- 💡 Autocomplete suggestions using a **Trie**.
- 📝 Exact phrase search using positional information.
- 📊 TF-IDF based document ranking.
- 🧹 Text preprocessing:
  - Tokenization
  - Lowercase normalization
  - Punctuation removal
  - Stop-word removal
  - Stemming
- 📍 Stores word frequency, positions, and line numbers for each document.

---

## 🛠 Tech Stack

- **Language:** C++20
- **Compiler:** g++ (MSYS2 MinGW)
- **Libraries:** STL (`vector`, `unordered_map`, `string`, `algorithm`, `fstream`, `sstream`)
- **Concepts:** Object-Oriented Programming, Data Structures & Algorithms

---

## 📁 Project Structure

```
SearchEngine/
│
├── data/
│   ├── doc1.txt
│   ├── doc2.txt
│   ├── doc3.txt
│   └── doc4.txt
│
├── Include/
│   ├── DocumentReader.h
│   ├── Tokenizer.h
│   ├── Trie.h
│   ├── InvertedIndex.h
│   ├── PhraseSearch.h
│   ├── Ranking.h
│   └── SearchEngine.h
│
├── src/
│   ├── main.cpp
│   ├── DocumentReader.cpp
│   ├── Tokenizer.cpp
│   ├── Trie.cpp
│   ├── InvertedIndex.cpp
│   ├── PhraseSearch.cpp
│   ├── Ranking.cpp
│   └── SearchEngine.cpp
```

---

## ⚙️ Algorithms & Data Structures

- Trie
- Positional Inverted Index
- TF-IDF Ranking
- Depth First Search (Trie Traversal)
- Hash Maps (`unordered_map`)
- Sorting
- String Processing

---

## 📖 Workflow

```
Text Documents
       │
       ▼
Document Reader
       │
       ▼
Tokenizer
       │
       ▼
Build Trie + Inverted Index
       │
       ▼
Search Engine
 ┌──────────────┬──────────────┐
 ▼              ▼              ▼
Word Search  Phrase Search  Auto Complete
                     │
                     ▼
               TF-IDF Ranking
```

---

## 📈 Time Complexity

| Operation | Complexity |
|-----------|------------|
| Build Index | O(Total Words) |
| Word Search | O(1) Average + Posting List |
| Trie Search | O(L) |
| Autocomplete | O(L + K) |
| Phrase Search | Position-based Matching |
| TF-IDF Ranking | O(P log P) |

Where:
- **L** = Length of the word
- **K** = Number of suggestions
- **P** = Number of matching documents

---

## ▶️ Build & Run

Compile using g++:

```bash
g++ src/*.cpp -IInclude -std=c++20 -o search_engine
```

Run:

```bash
./search_engine
```

---

## 📌 Current Functionalities

- Keyword Search
- Trie-based Autocomplete
- Phrase Search
- TF-IDF Ranking
- Word Frequency Tracking
- Position Tracking
- Line Number Tracking

---

## 📊 Sample Output

```
Enter Word : binary

Ranked Results
-------------------------
Document : data/doc1.txt
TF-IDF Score : 0.000019
```

---

## 🔮 Future Improvements

- Boolean Search (AND, OR, NOT)
- Wildcard Search
- Spell Correction
- SQLite Database Integration
- Persistent Index Storage
- Large-scale Dataset Support (Wikipedia/News Articles)
- Web-based User Interface

---

## 👨‍💻 Author

**Sayan Dolai**

B.Tech, Mechanical Engineering  
Indian Institute of Technology Kharagpur

---

## ⭐ If you found this project useful, consider giving it a Star!