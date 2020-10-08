path = input('Input path to func directory: ')
pos_count = int(input('Input positives count: '))
neg_count = int(input('Input negatives count: '))
arg = input('Make argument files? (y/n): ')

for j in range(2):
    if j == 0:
        end = '_in.txt'
    else:
        end = '_out.txt'

    for i in range(1, pos_count + 1):
        try:
            f1 = open(path + '\pos_' + str(i) + end, 'r')
        except IOError:
            f1 = open(path + '\pos_' + str(i) + end, 'w')
        finally:
            f1.close()

    for i in range(1, neg_count + 1):
        try:
            f1 = open(path + '\\neg_' + str(i) + end, 'r')
        except IOError:
            f1 = open(path + '\\neg_' + str(i) + end, 'w')
        finally:
            f1.close()
            
    if arg == 'y':
        end = '_args.txt'
        for i in range(1, pos_count + 1):
            try:
                f1 = open(path + '\pos_' + str(i) + end, 'r')
            except IOError:
                f1 = open(path + '\pos_' + str(i) + end, 'w')
            finally:
                f1.close()

        for i in range(1, neg_count + 1):
            try:
                f1 = open(path + '\\neg_' + str(i) + end, 'r')
            except IOError:
                f1 = open(path + '\\neg_' + str(i) + end, 'w')
            finally:
                f1.close()
