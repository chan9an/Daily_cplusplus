def get_median(value_frequencies, num_days):
    values_seen = 0
    start_median_window = num_days // 2 if num_days % 2 else num_days // 2 - 1
    end_median_window = num_days // 2
    median_value_1, median_value_2 = None, None
    for i in range(201):
        values_seen += value_frequencies[i]
        if values_seen > start_median_window and median_value_1 is None:
            median_value_1 = i
        if values_seen > end_median_window and median_value_2 is None:
            median_value_2 = i
            break
    return (median_value_1 + median_value_2) / 2
        
def activityNotifications(expenditure, d):
    notices = 0
    # Setting up initial value_frequencies for d days
    value_frequencies = [0 for _ in range(201)]
    for i in range(d):
        value_frequencies[expenditure[i]] += 1
    # Going through transaction that have enough trailing days
    for i in range(d, len(expenditure)):
        transaction_amount = expenditure[i]
        median = get_median(value_frequencies, d)
        if transaction_amount >= 2 * median:
            notices += 1
        # Getting ride of the left most trailing day
        left_most = expenditure[i - d]
        value_frequencies[left_most] -= 1
        # Adding the most recent transaction since it'll be the next 'trailing day'
        value_frequencies[transaction_amount] += 1
    return notices
