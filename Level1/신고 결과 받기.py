def solution(id_list, report, k):
    answer = [0 for i in range(len(id_list))]

    report_sort = list(set(report))
    people_list = []
    report_num = [0 for i in range(len(id_list))]

    for i in range(0, len(report_sort)) :
        people_list.append(report_sort[i].split())

    for i in range(0,len(id_list)) :
        for j in range(0,len(people_list)) :
            if id_list[i] == people_list[j] :
                report_num[i] += 1

    for i in range(0,len(id_list)) :
        if report_num[i] >= k :
            for j in range(0,len(people_list)) :
                if people_list[j][1] == id_list[i] :
                    answer[i] += 1
    return answer
