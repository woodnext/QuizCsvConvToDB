require "csv"

data = CSV.read("./File/quiz_data.csv", headers: true)

workbook_name = []
n = -1;

# 問題集名の取り出し
data.each do |line|
  if line[0] != workbook_name[n]
    n+=1
    workbook_name[n] = line[0]
  end
end

#workbook.csvの作成
CSV.open("./File/workbook.csv", "w") do |csv|
  csv << ["id", "name", "date", "level_id"]
  workbook_name.each_with_index do |data, index|
    csv << [index, data]
  end
end

#問題の取り出し・再フォーマット化
CSV.open("./File/question.csv", "w") do |csv|
  csv << ["id", "workbooks_id", "que", "ans", "anoans", "attribute", "total_crct_ans", "total_wrng_ans", ]
  data.each_with_index do |line, index|
    workbook_id = workbook_name.find_index { |n| n == line[0] }
    blank = ""

    csv << [index, workbook_id, line["問題文"], line["解答"], line["別解等"], blank, 0, 0]
  end
end
