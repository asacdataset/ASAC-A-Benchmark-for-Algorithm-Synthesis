# ASAC
ASAC: A Benchmark for Algorithm Synthesis

The dataset is organized as follows:

```
├── dataset                // Dataset
│ ├── NOIP2007-J            
│ │ ├── T2                  
│ │ │ ├── task.mzn         // Specification in MiniZinc
│ │ │ ├── task_c.docx      // Problem description in Chinese
│ │ │ ├── task_e.docx      // Problem description in English
│ │ │ ├── task_c.pdf       // Problem description in Chinese
│ │ │ ├── task_e.pdf       // Problem description in English
│ │ │ ├── task_c.txt       // Problem description in Chinese
│ │ │ ├── task_e.txt       // Problem description in English
│ │ │ ├── tests            // Tests
│ │ │ │	├── mzn_form       // Input with MiniZinc form
│ │ │ │	│ ├── x.dzn				   
│ │ │ │ ├── mzn_out        // Empty: MiniZinc answers can store here
│ │ │ │ ├── origin_form    // Input with natural language form
│ │ │ │ │ ├── x.in				  
│ │ │ │ ├── origin_out     // Empty: Code Generation anwers can store here
│ │ │ │ ├── ans            // Standard Output
│ │ │ │ │ ├── x.out				  

├── experiment             // Experiment 
│ ├── chatgpt_ans          // ChatGPT's answer of the problems
│ ├── chatgpt_score        // ChatGPT's score
│ │ ├── 20XX-J/S-TX        // In one problem
│ │ │ ├── X.out            // The output of the ChatGPT's code
│ │ │ ├── diff             // A directory to store comparison results
│ │ │ ├── gpt              // The program compiled from chatgpt_ans
│ │ │ ├── result.txt       // The score of the problem
```

ASAC can be obtained at https://github.com/asacdataset/ASAC.git
