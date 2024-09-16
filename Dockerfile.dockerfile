# Step 1: Use an official GCC image from Docker Hub
FROM gcc:latest

# Step 2: Set the working directory inside the container
WORKDIR /usr/src/app

# Step 3: Copy the C++ source code to the working directory
COPY greedy_graph_coloring.cpp .

# Step 4: Compile the C++ code
RUN g++ -o graph_coloring greedy_graph_coloring.cpp

# Step 5: Specify the command to run the compiled C++ program
CMD ["./graph_coloring"]
