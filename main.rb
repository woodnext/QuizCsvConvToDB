require "csv"

workbook_name = []
n = -1;
i = 0;

CSV.foreach("./File/quiz_data3.csv") do |line|
  if line[0] != workbook_name[n]
    n+=1
    workbook_name[n] = line[0]
  end
end

workbook_name.sort!

CSV.open("./File/workbook.csv", "w") do |csv|
  workbook_name.each do |data|
    csv << [data]
  end
end