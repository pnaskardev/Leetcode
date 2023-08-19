import java.util.*;

class Solution {

    public int[][] updateMatrix(int[][] mat) {
        int rows = mat.length;
        int columns = mat[0].length;
        int[][] directions = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

        Queue<int[]> queue = new LinkedList<>();
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (mat[i][j] == 0)
                    queue.add(new int[] { i, j });
                else
                    mat[i][j] = Integer.MAX_VALUE;
            }
        }

        while (!queue.isEmpty()) {
            int[] currentCell = queue.poll();
            int row = currentCell[0];
            int column = currentCell[1];

            for (int[] direction : directions) {
                int newRow = row + direction[0];
                int newColumn = column + direction[1];

                if (newRow < 0 || newRow >= rows || newColumn < 0 || newColumn >= columns
                        || mat[newRow][newColumn] <= mat[row][column] + 1)
                    continue;

                queue.add(new int[] { newRow, newColumn });
                mat[newRow][newColumn] = mat[row][column] + 1;
            }
        }
        return mat;
    }
}

class Prog {
    public static void main(String[] args) {

        int[][] mat = {
                { 0, 0, 0 },
                { 0, 1, 0 },
                { 0, 0, 0 }
        };

        int[][] result = new Solution().updateMatrix(mat);

        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[0].length; j++) {
                System.out.print(result[i][j] + " ");
            }
            System.out.println();
        }

    }
}