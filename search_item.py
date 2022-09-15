import pandas as pd

def keyowrd_search(filepath):
    df = pd.read_csv(filepath, index_col = 0)
    var = []

    print("top type : ", end = '')
    var.append(input())
    print("top color : ", end = '')
    var.append(input())
    print("bottom type : ", end = '')
    var.append(input())
    print("bottom color : ", end = '')
    var.append(input())
    
    for column in df:
        for i in range(len(var)):
            if(df[df[column] == var[i]].empty):
                print("Skip")
            else:
                print(df[df[column] == var[i]])

def type_search(filepath):
    df = pd.read_csv(filepath, index_col = 0)
    column_list = df.columns.tolist()
    var = []

    print("top type : ", end = '')
    var.append(input())
    print("top color : ", end = '')
    var.append(input())
    print("bottom type : ", end = '')
    var.append(input())
    print("bottom color : ", end = '')
    var.append(input())

    for i in range(len(column_list)):
        for j in range(len(var)):
            if (df[column_list[i]] == var[j]).any():
                if i == j:
                    search_df.append(df[df[column_list[i]] == var[j]])
    print(search_df)
                

def main():
    filepath = "/workspace/test_jhlee/metadata_project/output.csv"
    type_search(filepath)

if __name__ == '__main__':
    main()
