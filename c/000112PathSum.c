bool hasPathSum(struct TreeNode* root, int targetSum) {
	// The trivial case if root is null.
	if (root == NULL)
	{
		return false;
	}

	// Variable that holds the operation for targetSum minus
	// the root value.
	int remainder = targetSum - root->val;

	// Check to see if it is a child node.
	if ((root->right == NULL)&&(root->left == NULL))
	{
		// If the remainder is 0, it is a path
		// that leads to 0
		if (remainder == 0)
		{
		    return true;
		}
		// Otherwise it isn't a valid path
		else
		{
		    return false;
		}
	}
	// Recurse down the right path first.
	// If a valid path exists, return true.
	else if (hasPathSum(root->right, remainder)) 
	{
		return true;
	}
	// If the right paths don't hold up
	// then recurse down the left path.
	// If a valid path exists, return true.
	else if (hasPathSum(root->left, remainder))
	{
		return true;
	}

	// If all paths are exhausted and no sum 
	// exists from root to children, then
	// return false.
	return false;
}
