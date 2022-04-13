import sys

class statistics:
    max_soc, min_soc, max_temp, min_temp, mov_avg_soc, mov_avg_temp = 0, 0, 0, 0, 0, 0


def get_data_from_sender():
    data = sys.stdin.read()
    return data

def split_data_from_sender(data):
    data_list = data.split('\n')
    data_list[0] = data_list[0].replace("SOC,", "")
    data_list[1] = data_list[1].replace("TEMPERATURE,", "")
    soc_list = data_list[0].split(' ')
    temp_list = data_list[1].split(' ')
    #converting str in int
    return  list(map(int, soc_list)), list(map(int, temp_list))

def compute_statitics(soc_list, temp_list, index):
    stats = statistics()
    stats.max_soc = max(soc_list[0:index])
    stats.min_soc = min(soc_list[0:index])
    stats.max_temp = max(temp_list[0:index])
    stats.min_temp = min(temp_list[0:index])
    stats.mov_avg_soc = round(sum(soc_list[0:index][-5:])/5,2)
    stats.mov_avg_temp = round(sum(temp_list[0:index][-5:])/5,2)
    return stats

def process_data_from_sender(data):
    soc_list,temp_list = split_data_from_sender(data)
    for index in range(1,50):
        stats = compute_statitics(soc_list, temp_list, index)
        print ("Soc :{}\tTemp:{}\tMax Soc:{}\tMin Soc:{}\tMax Temp:{}\tMin Temp:{}\tMoving Avg Soc:{}\tMoving Avg Temp:{}".format(soc_list[index], temp_list[index],stats.max_soc, stats.min_soc, stats.max_temp, stats.min_temp, stats.mov_avg_soc, stats.mov_avg_temp))
    return stats

if __name__ == '__main__': 
    data = get_data_from_sender()
    process_data_from_sender(data)
