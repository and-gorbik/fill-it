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
        for i in range(count):
            rnd = random.randint(0, len(correct_items) - 1)
            f.write(correct_items[rnd])

if __name__ == '__main__':
    run()