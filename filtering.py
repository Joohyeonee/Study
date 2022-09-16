import pandas as pd

def search(filepath, filter):
    df = pd.read_csv(filepath)
    column_list = df.columns.values.tolist()
    
    search_df = pd.DataFrame(columns = column_list)
    
    for column in df:
        search_df = search_df.append(df[df[column] == filter])
                
    or_list = search_df[~search_df.duplicated()]

    print("검색조건 일부 만족")
    print(or_list)  
                
def main():
    filepath = "your_filepath"

    print("검색 : ", end = '')
    filter = input()
    
    search(filepath, filter)

if __name__ == '__main__':
    main()
