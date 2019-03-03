import random

def run(filename='data.txt', count=0):
    correct_items = [
        "....\n####\n....\n....\n",
        ".#..\n.#..\n.#..\n.#..\n",
        ".##.\n.##.\n....\n....\n",
        ".#..\n.#..\n.##.\n....\n",
        ".##.\n..#.\n..#.\n....\n",
        "###.\n#...\n....\n....\n",
        "...#\n.###\n....\n....\n",
        ".##.\n.#..\n.#..\n....\n",
        "....\n...#\n...#\n..##\n",
        ".#..\n.###\n....\n....\n",
        ".###\n...#\n....\n....\n",
        ".#..\n.##.\n..#.\n....\n",
        "..##\n.##.\n....\n....\n",
        "..#.\n.##.\n.#..\n....\n",
        "##..\n.##.\n....\n....\n",
        "....\n....\n..#.\n.###\n",
        "...#\n..##\n...#\n....\n",
        "..#.\n..##\n..#.\n....\n",
        ".###\n..#.\n....\n....\n",
    ]
    if count > 26 or count < 1:
        count = random.randint(1, 26)
    with open(filename, "w") as f:
        result = [
            correct_items[random.randint(0, len(correct_items) - 1)]
            for i in range(count)
        ]
        f.write("\n".join(result))

            

if __name__ == '__main__':
    run()