說明文件：

1. 測資的路徑應為 /data/secret/ 或是 /data/sample/ 前者為大測資 後者為範例測資；前者一定需要，後者則否。
2. 輸入輸出副檔名分別為 .in 及 .ans 主檔名需一致
3. MakeCase 裡有三個主要程式碼 input.cpp input_validator.cpp output.cpp 分別代表 產生輸入程式碼、檢查輸入程式碼、產生輸出程式碼
4. 三個程式碼均以C++撰寫且附上註解，若有不懂之處，可提問。
5. 可使用 "make input", "make inputv", "make output" 等指令分別編譯三種程式碼
6. 上述產生的編譯指令會產生 input.exe, input_validator.exe, output.exe 三個執行檔
7. 在執行 input_validator 及 output.exe 之前 請先確認有輸入測資（執行過 input.exe）
8. 總體測資盡量不要超過50MB（會放不上Judge）
9. 測資完成後，將 /data/secret/ 以 zip 形式壓縮（Domjudge 格式）

10. Problem 內存放題本，一定要有pdf檔，至於要多放docx或是其他也可。
11. 題本格式不拘，但必須有「題目敘述」、「輸入格式說明」、「輸出格式說明」、「技術規格」、「範例輸入輸出」（技術規格可合併於輸入格式及輸出格式）
12. 盡量不要出無input題目
13. 現階段盡量不要出「小數點」、「多重答案」的題目，如果需求，請找我討論。

14. submissions 內有放有 AC , WA , TLE , MLE 等Code，前三者盡量都要有，MLE 不一定需要。
15. Domjudge 帳號密碼為你們的學號，已經幫你們設置管理員身份。
16. Domjudge 上點選 Problems > 最底下有Problem archive(s) （不是Add new problem），選擇競賽或no link 上傳 zip 檔，上傳完畢後，編輯及上傳題本

17. 有問題歡迎提出，隨時可補充。 