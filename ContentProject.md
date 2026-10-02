*Tiếng việt
Yêu cầu chức năng & kỹ thuật phải xây dựng
1.Cài đặt thuật toán Euclid cổ điển (sử dụng phép chia lấy phần dư / modulo).
2.Cài đặt thuật toán Binary GCD — Thuật toán Stein (chỉ sử dụng phép trừ và dịch bit, không dùng phép chia hay lấy dư).
3.Đo hiệu năng (Benchmark) cả hai thuật toán trên ít nhất 3 nhóm đầu vào: các cặp số ngẫu nhiên, các cặp số nguyên tố cùng nhau (coprime), và các cặp số đều là lũy thừa của 2 nhân với một thừa số chung.
4.Báo cáo số lần lặp/số bước thực hiện và thời gian chạy thực tế (wall-clock time) cho từng nhóm đầu vào và từng thuật toán.
5.Giải thích kèm ví dụ tính toán chi tiết từng bước (worked example) lý do tại sao Binary GCD lại vượt trội hơn Euclid trên phần cứng mà ở đó phép chia tốn nhiều chi phí tính toán.
Bonus( + điểm) : thêm 1 thuật toán nữa ( có thể là thuật toán Euclid mở rộng)

Test case tối thiểu
1.Ví dụ nhỏ có thể truy vết bằng tay (hand-traceable): Tự xác minh thủ công và so sánh kết quả đó với đầu ra của chương trình (ít nhất 1 ví dụ).
2.Đầu vào quy mô lớn: Minh họa các đặc tính hiệu năng đã được phân tích và đánh giá (ít nhất 1 trường hợp).
3.Trường hợp biên (edge case): Đầu vào rỗng, chỉ chứa một phần tử, tất cả giá trị bị trùng lặp, hoặc đầu vào đối kháng (adversarial input) có liên quan đến đề tài (ít nhất 1 trường hợp).

Sản phẩm dự kiến
1.Mã nguồn (Source code): Đi kèm hướng dẫn chi tiết cách biên dịch và chạy chương trình.
2.Báo cáo bằng văn bản (Written report): Bao gồm phần phát biểu lại bài toán, thiết kế hệ thống, phần Tự giải trình (Self-Explanation) cho từng yêu cầu, phân tích độ phức tạp (liên hệ số bước Euclid trong trường hợp xấu nhất với dãy Fibonacci theo định lý Lamé), minh chứng kiểm thử và Nhật ký sử dụng AI (AI Usage Log).
3.Mức độ sẵn sàng bảo vệ trực tiếp (Oral/live-defense readiness): Chuẩn bị kiến thức để trả lời vấn đáp trực tiếp theo quy định chung.



*Tiếng anh
Yêu cầu chức năng & kỹ thuật phải xây dựng:
1.Implement the classic Euclidean algorithm (with remainder/modulo).
2.Implement the binary GCD algorithm (using only subtraction and bit shifts, no division/modulo).
3.Benchmark both on at least 3 categories of input: random pairs, coprime pairs, and pairs that are both powers of two times a common factor.
4.Report the number of iterations/steps and wall-clock time for each category and algorithm.
5.Explain, with a worked example, why the binary GCD algorithm can outperform Euclid's on hardware where division is expensive.
Trọng tâm thuật toán: Number-theoretic algorithms.
Phân tích độ phức tạp (bắt buộc trong báo cáo): Relate the worst-case number of Euclidean steps to Fibonacci numbers (Lamé's theorem) and discuss your data in that light.

Test case tối thiểu:
1.At least one small hand-traceable example you verify by hand and compare to your program's output.
2.At least one large-scale input demonstrating the performance characteristics discussed above.
3.At least one edge case (empty input, single element, all-duplicate values, or an adversarial input relevant to this topic).
Ghi chú thêm: Bonus: extend one algorithm to compute the extended GCD (Bezout coefficients) and explain one use for it.
Sản phẩm dự kiến:

Deliverables (theo đề bài gốc):
1.Source code with build/run instructions.
2.Written report including: problem restatement, design, Self-Explanation for every requirement above (see the root README.md Academic Integrity & AI Usage Policy), complexity analysis, test evidence, and the AI Usage Log.
3.Oral/live-defense readiness — see root README.md.
